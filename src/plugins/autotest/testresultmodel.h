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

#ifndef TESTRESULTMODEL_H
#define TESTRESULTMODEL_H

#include "testresult.h"

#include <QAbstractItemModel>
#include <QSortFilterProxyModel>
#include <QFont>
#include <QSet>

#include <utils/treemodel.h>

namespace Autotest {
namespace Internal {

class TestResultItem : public Utils::TreeItem
{
public:
    explicit TestResultItem(const TestResultPtr &testResult);
    ~TestResultItem();
    QVariant data(int column, int role) const;
    const TestResult *testResult() const { return m_testResult.data(); }
    void updateDescription(const QString &description);
    void updateResult();

private:
    TestResultPtr m_testResult;
};

class TestResultModel : public Utils::TreeModel
{
public:
    explicit TestResultModel(QObject *parent = 0);
    QVariant data(const QModelIndex &idx, int role) const;

    void addTestResult(const TestResultPtr &testResult, bool autoExpand = false);
    void removeCurrentTestMessage();
    void clearTestResults();

    TestResult testResult(const QModelIndex &idx);

    int maxWidthOfFileName(const QFont &font);
    int maxWidthOfLineNumber(const QFont &font);

    int resultTypeCount(Result::Type type) const { return m_testResultCount.value(type, 0); }
    int disabledTests() const { return m_disabled; }

private:
    QMap<Result::Type, int> m_testResultCount;
    int m_widthOfLineNumber;
    int m_maxWidthOfFileName;
    int m_disabled;
    QList<int> m_processedIndices;
    QFont m_measurementFont;
};

class TestResultFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    TestResultFilterModel(TestResultModel *sourceModel, QObject *parent = 0);

    void enableAllResultTypes();
    void toggleTestResultType(Result::Type type);
    void clearTestResults();
    bool hasResults();
    TestResult testResult(const QModelIndex &index) const;

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
    TestResultModel *m_sourceModel;
    QSet<Result::Type> m_enabled;
};

} // namespace Internal
} // namespace Autotest

#endif // TESTRESULTMODEL_H
