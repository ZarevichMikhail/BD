#ifndef WORKERDELEGATE_H
#define WORKERDELEGATE_H

#include <QObject>

class WorkerDelegate : public QObject
{
    Q_OBJECT
public:
    explicit WorkerDelegate(QObject *parent = nullptr);

signals:
};

#endif // WORKERDELEGATE_H
