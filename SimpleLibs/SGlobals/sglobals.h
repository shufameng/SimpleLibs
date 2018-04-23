#ifndef SGLOBALS_H
#define SGLOBALS_H

#include "sglobals_global.h"

// Dirs
#define DOWNLOAD_DIR "download"
#define LOG_DIR "log"
#define VERSION_DIR "version"
#define LANGUAGE_DIR "language"
#define APP_LOG_PREFIX "app_"
#define UPDATE_LOG_PREFIX "update_"

class SLanguageManager;
class SLogger;
class SSettings;
class QNetworkAccessManager;
class SGLOBALSSHARED_EXPORT SGlobals
{

public:
    SGlobals();
    ~SGlobals();


    static QNetworkAccessManager *sgNetworkManager;
    static SLanguageManager *sgLangManager;
    static SLogger *sgLogger;
    static SSettings *sgSettings;
};

#endif // SGLOBALS_H
