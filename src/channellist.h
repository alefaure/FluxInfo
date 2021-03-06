#ifndef CHANNELLIST_H
#define CHANNELLIST_H

#include <QObject>
#include "channel.h"

class ChannelList : public QObject
{
    Q_OBJECT
    QList<Channel*> m_channels;
public:
    explicit ChannelList(QObject *parent = nullptr);

    void append(Channel* channel);
    Channel *at(int place) const;
    int count() const;
    void createChannel(QString lien, QString titre);
    void removeChannel(int position);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);

public slots:
};

#endif // CHANNELLIST_H
