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

#ifndef REMOTELINUXDEBUGSUPPORT_H
#define REMOTELINUXDEBUGSUPPORT_H

#include "abstractremotelinuxrunsupport.h"

namespace Debugger { class DebuggerRunControl; }

namespace RemoteLinux {

namespace Internal { class LinuxDeviceDebugSupportPrivate; }

class REMOTELINUX_EXPORT LinuxDeviceDebugSupport : public AbstractRemoteLinuxRunSupport
{
    Q_OBJECT

public:
    LinuxDeviceDebugSupport(ProjectExplorer::RunConfiguration *runConfig,
            Debugger::DebuggerRunControl *runControl);
    ~LinuxDeviceDebugSupport();

protected:
    void startExecution();
    void handleAdapterSetupFailed(const QString &error);
    void handleAdapterSetupDone();

private slots:
    void handleRemoteSetupRequested();
    void handleAppRunnerError(const QString &error);
    void handleRemoteOutput(const QByteArray &output);
    void handleRemoteErrorOutput(const QByteArray &output);
    void handleAppRunnerFinished(bool success);
    void handleProgressReport(const QString &progressOutput);

    void handleRemoteProcessStarted();
    void handleDebuggingFinished();

private:
    void showMessage(const QString &msg, int channel);

    Internal::LinuxDeviceDebugSupportPrivate * const d;
};

} // namespace RemoteLinux

#endif // REMOTELINUXDEBUGSUPPORT_H
