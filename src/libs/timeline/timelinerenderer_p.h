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

#ifndef TIMELINERENDERER_P_H
#define TIMELINERENDERER_P_H

#include "timelinerenderer.h"
#include "timelineabstractrenderer_p.h"

namespace Timeline {

class TimelineRenderer::TimelineRendererPrivate :
        TimelineAbstractRenderer::TimelineAbstractRendererPrivate {
public:
    TimelineRendererPrivate(TimelineRenderer *q);
    ~TimelineRendererPrivate();

    void clear();

    int rowFromPosition(int y) const;

    void manageClicked();
    void manageHovered(int mouseX, int mouseY);

    static const int SafeFloatMax = 1 << 12;

    void resetCurrentSelection();

    TimelineRenderState *findRenderState();

    struct {
        qint64 startTime;
        qint64 endTime;
        int row;
        int eventIndex;
    } currentSelection;

    QVector<QHash<qint64, TimelineRenderState *> > renderStates;
    TimelineRenderState *lastState;

private:
    TimelineRenderer *q_ptr;
    Q_DECLARE_PUBLIC(TimelineRenderer)
};

} // namespace Timeline

#endif // TIMELINERENDERER_P_H

