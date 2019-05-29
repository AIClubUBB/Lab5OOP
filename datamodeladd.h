#ifndef DATAMODELADD_H
#define DATAMODELADD_H

#include <QObject>
#include <QWidget>
#include <QListView>
#include <QAbstractListModel>
#include "Repo.h"

class datamodeladd:public QAbstractListModel
{
private:
public:
    watchlist WL;
    datamodeladd(QObject *parent) : QAbstractListModel(parent)
    {
        this->WL = watchlist();
    }
    datamodeladd();
    int rowCount(const QModelIndex& parent = QModelIndex()) const
    {
            return this->WL.movieList.size();
    }
    QVariant data (const QModelIndex& index, int role = Qt::DisplayRole) const
    {
        vector<Movie>data=WL.movieList;
        if (role == Qt::DisplayRole)
            return QVariant(data[index.row()].getTitle().c_str());
        return QVariant();
    }
};

#endif // DATAMODELADD_H
