/****************************************************************************
**
** Copyright (C) 2016 Jochen Becher
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

#ifndef QMT_DIAGRAMSVIEWINTERFACE_H
#define QMT_DIAGRAMSVIEWINTERFACE_H

namespace qmt {

class MDiagram;
class DiagramSceneModel;

class DiagramsViewInterface
{
public:
    virtual ~DiagramsViewInterface() { }

    virtual void openDiagram(MDiagram *) = 0;
    virtual void closeDiagram(const MDiagram *) = 0;
    virtual void closeAllDiagrams() = 0;
    virtual void onDiagramRenamed(const MDiagram *) = 0;
};

} // namespace qmt

#endif // QMT_DIAGRAMSVIEWINTERFACE_H
