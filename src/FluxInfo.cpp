#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include "rss.h"
#include "channel.h"
#include "channelmodel.h"
#include "parserrss.h"
#include "fluxmanager.h"


#include <sailfishapp.h>

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


    qmlRegisterType<ChannelModel>("ChannelModel", 1, 0, "ChannelModel" );
    qmlRegisterType<FluxManager>("FluxManager", 1, 0, "FluxManager" );
    /*
    QList<Rss*> mesRss;

    mesRss.append(new Rss(new Channel("Mes couilles sur ton front ca fait une licorne!")));
    mesRss.append(new Rss(new Channel("Windows c'est de la merde")));
    */

    FluxManager manager;

    QQuickView *view = SailfishApp::createView();
    view -> rootContext() -> setContextProperty("mesChannels", manager.channels());
    view -> rootContext() -> setContextProperty("manager", &manager);

    view -> setSource(SailfishApp::pathToMainQml());
    view -> show();

    return app -> exec();
}
