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

#include "messagemanager.h"
#include "messageoutputwindow.h"

#include <extensionsystem/pluginmanager.h>
//OPENMV-DIFF//
#include "outputwindow.h"
//OPENMV-DIFF//

using namespace Core;

static MessageManager *m_instance = 0;
Internal::MessageOutputWindow *m_messageOutputWindow = 0;

QObject *MessageManager::instance()
{
    return m_instance;
}

MessageManager::MessageManager()
{
    m_instance = this;
    m_messageOutputWindow = 0;
    qRegisterMetaType<MessageManager::PrintToOutputPaneFlags>();
}

MessageManager::~MessageManager()
{
    if (m_messageOutputWindow) {
        ExtensionSystem::PluginManager::removeObject(m_messageOutputWindow);
        delete m_messageOutputWindow;
    }
    m_instance = 0;
}

void MessageManager::init()
{
    m_messageOutputWindow = new Internal::MessageOutputWindow;
    ExtensionSystem::PluginManager::addObject(m_messageOutputWindow);
}

void MessageManager::showOutputPane()
{
    if (m_messageOutputWindow)
        m_messageOutputWindow->popup(IOutputPane::ModeSwitch);
}

void MessageManager::write(const QString &text)
{
    write(text, NoModeSwitch);
}

void MessageManager::write(const QString &text, PrintToOutputPaneFlags flags)
{
    if (!m_messageOutputWindow)
        return;
    if (flags & Flash) {
        m_messageOutputWindow->flash();
    } else if (flags & Silent) {
        // Do nothing
    } else {
        m_messageOutputWindow->popup(IOutputPane::Flag(int(flags)));
    }

    m_messageOutputWindow->append(text + QLatin1Char('\n'));
}

//OPENMV-DIFF//
OutputWindow *MessageManager::outputWindow()
{
    if (!m_messageOutputWindow)
        return 0;
    return m_messageOutputWindow->m_widget;
}
void MessageManager::printData(const QByteArray &data)
{
    if (!m_messageOutputWindow)
        return;
    m_messageOutputWindow->append(QString::fromUtf8(data));
}
void MessageManager::grayOutOldContent()
{
    if (!m_messageOutputWindow)
        return;
    m_messageOutputWindow->m_widget->grayOutOldContent();
}
void MessageManager::popup()
{
    if (!m_messageOutputWindow)
        return;
    m_messageOutputWindow->popup(IOutputPane::NoModeSwitch);
}
void MessageManager::flash()
{
    if (!m_messageOutputWindow)
        return;
    m_messageOutputWindow->flash();
}
//OPENMV-DIFF//
