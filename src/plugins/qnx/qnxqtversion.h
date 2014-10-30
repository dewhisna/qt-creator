/**************************************************************************
**
** Copyright (C) 2012 - 2014 BlackBerry Limited. All rights reserved.
**
** Contact: BlackBerry (qt@blackberry.com)
** Contact: KDAB (info@kdab.com)
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://www.qt.io/licensing.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef QNX_INTERNAL_QNXQTVERSION_H
#define QNX_INTERNAL_QNXQTVERSION_H

#include "qnxconstants.h"
#include "qnxabstractqtversion.h"

namespace Qnx {
namespace Internal {

class QnxQtVersion : public QnxAbstractQtVersion
{
    Q_DECLARE_TR_FUNCTIONS(Qnx::Internal::QnxQtVersion)
public:
    QnxQtVersion();
    QnxQtVersion(QnxArchitecture arch, const Utils::FileName &path,
                 bool isAutoDetected = false,
                 const QString &autoDetectionSource = QString());
    QnxQtVersion *clone() const;
    ~QnxQtVersion();

    QString type() const;

    QString description() const;

    Core::FeatureSet availableFeatures() const;
    QString platformName() const;
    QString platformDisplayName() const;

    QString sdkDescription() const;

private:
    QList<Utils::EnvironmentItem> environment() const;
};

} // namespace Internal
} // namespace Qnx

#endif // QNX_INTERNAL_QNXQTVERSION_H