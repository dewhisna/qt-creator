/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#ifndef WINRTRUNCONFIGURATION_H
#define WINRTRUNCONFIGURATION_H

#include <projectexplorer/runconfiguration.h>

namespace WinRt {
namespace Internal {

class WinRtRunConfiguration : public ProjectExplorer::RunConfiguration
{
    Q_OBJECT

public:
    explicit WinRtRunConfiguration(ProjectExplorer::Target *parent, Core::Id id);

    QWidget *createConfigurationWidget() override;
    bool isEnabled() const override { return true; } // Always enabled like DLL run control
    QVariantMap toMap() const override;
    bool fromMap(const QVariantMap &map) override;

    const QString &proFilePath() const { return m_proFilePath; }
    QString arguments() const;
    bool uninstallAfterStop() const { return m_uninstallAfterStop; }

signals:
    void argumentsChanged(QString);
    void uninstallAfterStopChanged(bool);

public slots:
    void setUninstallAfterStop(bool b);

private:
    QString m_proFilePath;
    bool m_uninstallAfterStop;
};

} // namespace Internal
} // namespace WinRt

#endif // WINRTRUNCONFIGURATION_H
