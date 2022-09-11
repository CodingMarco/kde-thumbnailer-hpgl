/*
 *  This file is part of kde-thumbnailer-hpgl
 *  Inspired by kde-thumbnailer-apk by Luca Weiss <luca (at) z3ntu (dot) xyz>
 *  Copyright (C) 2013 Ni Hui <shuizhuyuanluo@126.com>
 *  Copyright (C) 2017-2019 Luca Weiss <luca (at) z3ntu (dot) xyz>
 *  Copyright (C) 2022 Marco von Rosenberg <codingmarco@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "hpglcreator.h"

#include <QDebug>
#include <QImage>
#include <QColor>
#include <QProcess>

extern "C" {
    Q_DECL_EXPORT ThumbCreator* new_creator()
    {
        return new HpglCreator;
    }
}

HpglCreator::HpglCreator()
{
}

HpglCreator::~HpglCreator()
{
}

bool HpglCreator::create(const QString& path, int /*width*/, int /*height*/, QImage& img)
{
    QString program = "hp2xx";
    QStringList args;
    // -m pbm: PBM image format is the fastest as it requires the least processing
    // -I -f-: Output image to stdout
    args << "-m" << "pbm" << "-I" << "-f-" << path;
    QProcess hp2xxProcess;
    hp2xxProcess.start(program, args);
    QByteArray data;

    while(hp2xxProcess.waitForReadyRead())
    {
        data.append(hp2xxProcess.readAll());
    }

    img = QImage::fromData(data, "PBM");

    qDebug() << path;

    if (img.isNull()) {
        qDebug() << "Failed to get image";
        return false;
    }

    return true;
}
