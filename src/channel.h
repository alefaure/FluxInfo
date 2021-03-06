#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include "channelitem.h"

class Channel : public QObject
{
Q_OBJECT
private:
    Q_PROPERTY(QList<ChannelItem*> articles READ articles WRITE setArticles NOTIFY articlesChanged)
    Q_PROPERTY(QString titre READ titre WRITE setTitre NOTIFY titreChanged)
    Q_PROPERTY(QString lien READ lien WRITE setLien NOTIFY lienChanged)
    QString m_titre;
    QString m_lien;
    QList<ChannelItem*> m_articles;

public:
    Channel(QString titre, QString lien);

    QString titre() const;
    QString lien() const;
    QList<ChannelItem*> articles() const;

public slots:
    void setTitre(QString titre);
    void setLien(QString lien);
    void setArticles(QList<ChannelItem*> articles);

signals:
    void lienChanged(QString lien);
    void titreChanged(QString titre);
    void articlesChanged(QList<ChannelItem*> articles);
    void channelChanged();
};

#endif // CHANNEL_H
