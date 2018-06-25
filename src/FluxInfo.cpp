#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include "rss.h"
#include "channel.h"
#include "channelmodel.h"
#include "channelitemmodel.h"
#include "parserrss.h"
#include "fluxmanager.h"


#include <sailfishapp.h>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QGuiApplication* app = SailfishApp::application(argc, argv);

    // SailfishApp::main() will display "qml/FluxInfo.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    ChannelList model;
    ChannelItemList modelItem;

    qmlRegisterType<ChannelModel>("ChannelModel", 1, 0, "ChannelModel" );
    qmlRegisterType<ChannelItemModel>("ChannelItemModel", 1, 0, "ChannelItemModel" );

    /*
    QList<Rss*> mesRss;

    mesRss.append(new Rss(new Channel("Mes couilles sur ton front ca fait une licorne!")));
    mesRss.append(new Rss(new Channel("Windows c'est de la merde")));
    */

    FluxManager manager;
    // manager.loadData();
    QQuickView *view = SailfishApp::createView();

    view -> rootContext() -> setContextProperty("mesChannels", manager.channels());
    view -> rootContext() -> setContextProperty("manager", &manager);
    view -> rootContext() -> setContextProperty("mesChannelItems", &modelItem);


    view -> setSource(SailfishApp::pathToMainQml());
    view -> show();

    return app -> exec();
}
