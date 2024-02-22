#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Howl)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer(this);

    ui->s_volume->setValue(100);
    ui->p_position->setValue(0);
    ui->s_volume->setRange(0, 100);

    connect (ui->b_add, &QPushButton::clicked, this, &Howl::addSong);
    connect (ui->listWidget, &QListWidget::itemClicked, this, &Howl::setSong);
    connect (ui->b_remove, &QPushButton::clicked, this, &Howl::removeSong);
    connect (ui->b_previous, &QPushButton::clicked, this, &Howl::previous);
    connect (ui->b_next, &QPushButton::clicked, this, &Howl::next);
    connect (ui->s_volume, &QSlider::valueChanged, this, &Howl::updateVolume);
    connect (ui->b_playPause, &QPushButton::clicked, this, &Howl::playPause);
    connect (m_player, &QMediaPlayer::positionChanged, this, &Howl::updatePosition);
    connect (m_player, &QMediaPlayer::durationChanged, this, &Howl::updateDuration);
}

Howl::~Howl()
{
    delete ui;
}

void Howl::playPause()
{
    if (m_player->state() == QMediaPlayer::PlayingState) {
        m_player->pause();
    } else {
        m_player->play();
    }
}

void Howl::next()
{
    QListWidgetItem* nextItem = ui->listWidget->item(ui->listWidget->currentRow() + 1);

    if (nextItem) {
        ui->listWidget->setCurrentItem(nextItem);
        this->setSong(nextItem);
    }
}

void Howl::previous()
{
    QListWidgetItem* previousItem = ui->listWidget->item(ui->listWidget->currentRow() - 1);

    if (previousItem) {
        ui->listWidget->setCurrentItem(previousItem);
        this->setSong(previousItem);
    }
}

void Howl::updateDuration()
{
    ui->p_position->setMaximum(m_player->duration() / 1000);
}

void Howl::updatePosition(qint64 pos)
{
    ui->p_position->setValue(pos / 1000);
}

void Howl::addSong()
{
    QString path = QFileDialog::getOpenFileName(this, "Select file", QDir::homePath(), "*.mp3");
    ui->listWidget->addItem(path);
}

void Howl::setSong(QListWidgetItem *item)
{
    QString path = item->text();
    ui->l_songName->setText(path);
    m_player->setMedia(QUrl::fromLocalFile(path));
}

void Howl::removeSong()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Howl::updateVolume(int volume)
{
    m_player->setVolume(volume);
}
