/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2015 Ricardo Villalba <rvm@users.sourceforge.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "paths.h"
#include <QLibraryInfo>
#include <QLocale>
#include <QFile>
#include <QRegExp>
#include <QDir>
#include <QDebug>

QString Paths::app_path;
QString Paths::config_path;

void Paths::setAppPath(QString path) {
	app_path = path;
}

QString Paths::appPath() {
	return app_path;
}

QString Paths::translationPath() {
    QString path;
    if (QDir("/usr/share/kylin-video/translations").exists()) {
        path = "/usr/share/kylin-video/translations";
        return path;
    }
    else {
        return appPath() + "/translations";
    }
}

QString Paths::shortcutsPath() {
    return appPath() + "/shortcuts";
}

QString Paths::qtTranslationPath() {
    return QLibraryInfo::location(QLibraryInfo::TranslationsPath);
}

void Paths::setConfigPath(QString path) {
	config_path = path;
}

QString Paths::configPath() {
    //kobe
    if (!config_path.isEmpty()) {
        return config_path;
    } else {
        return QDir::homePath() + "/.config/kylin-video";
    }
}

QString Paths::iniPath() {
	return configPath();
}
