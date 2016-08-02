#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
 #include <QMediaMetaData>
#include <QString>

class MediaPlayer: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int volume READ getVolume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(int progress READ getProgress WRITE setProgress NOTIFY progressChanged)
    Q_PROPERTY(int duration READ getDuration NOTIFY durationChanged)
    Q_PROPERTY(QString title READ getTitle NOTIFY durationChanged)
    Q_PROPERTY(QString fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)

public:
    ~MediaPlayer();
    MediaPlayer();
    int getVolume() const;
    int getProgress() const;
    int getDuration() const;
    QString getTitle() const;

    void setVolume(int volume);
    void setProgress(int progress);
    void setFileUrl(QString url);


private:
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;

    int m_volume;
    int m_progress;
    int m_duration;
    QString m_fileUrl;
    QString m_mediaTitle;

public slots:
    void mediaPlay();
    void mediaPause();
    void mediaStop();
    void mediaNext();
    void mediaPrevious();
    void mediaJump(int);
    void mediaRemove(int);
    void changeProgress(int);
    void changeDuration(int);
    void changeFileUrl(QString);


signals:
    int volumeChanged();
    int progressChanged();
    int durationChanged();
    int fileUrlChanged();

};

#endif // MEDIAPLAYER_H
