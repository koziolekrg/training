#include "mediaplayer.h"

MediaPlayer::~MediaPlayer()
{

}

MediaPlayer::MediaPlayer()
    :m_volume(50), m_progress(0)
{

    m_player = new QMediaPlayer();
    m_playlist = new QMediaPlaylist();

    m_player->setPlaylist(m_playlist);

    connect(m_player, &QMediaPlayer::durationChanged,  this, &MediaPlayer::changeDuration);
    connect(m_player, &QMediaPlayer::positionChanged, this, &MediaPlayer::changeProgress);
}
bool MediaPlayer::playerStatus()
{
    return m_player->state();
}

void MediaPlayer::mediaPlay()
{
    m_player->play();
}

void MediaPlayer::mediaPause()
{
    m_player->pause();
}

void MediaPlayer::mediaStop()
{
    m_player->stop();
}

void MediaPlayer::mediaNext()
{
    m_playlist->next();
}

void MediaPlayer::mediaPrevious()
{
    m_playlist->previous();
}

void MediaPlayer::mediaJump(int index)
{
   m_playlist->setCurrentIndex(index);
   m_player->play();
}

void MediaPlayer::mediaRemove(int index)
{
    m_playlist->removeMedia(index);
}

int MediaPlayer::getVolume() const
{
    return m_volume;
}

int MediaPlayer::getProgress() const
{
    return m_player->position();
}

int MediaPlayer::getDuration() const
{
    return m_player->duration();
}

QString MediaPlayer::getTitle() const
{
    QString m_fileUrl = m_player->currentMedia().canonicalUrl().toString();
    return  m_fileUrl;
}

void MediaPlayer::setVolume(int volume)
{
    m_volume = volume;
    m_player->setVolume(m_volume);
}

void MediaPlayer::setProgress(int progress)
{
    if(progress == m_player->position())
        return;
    else
        m_player->setPosition(progress);
}

void MediaPlayer::setFileUrl(QString url)
{
    m_playlist->addMedia(QUrl::fromLocalFile(url));
    m_fileUrl = url;;
}

void MediaPlayer::changeProgress(int value)
{
    m_progress= value;
    emit progressChanged();

}

void MediaPlayer::changeDuration(int value)
{
    m_duration = value;
    emit durationChanged();
}

void MediaPlayer::changeFileUrl(QString url)
{
    m_fileUrl = url;
    emit fileUrlChanged();
}
