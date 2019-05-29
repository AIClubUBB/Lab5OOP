#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QWidget>
#include <QListView>
#include <QAbstractListModel>
#include "Repo.h"

class DataModel: public QAbstractListModel
{
private:
    watchlist WL;
    vector<Movie> aux;
public:
    DataModel(QObject *parent) : QAbstractListModel(parent)
    {
        this->WL = watchlist();
    }
    DataModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const
    {
            return this->WL.movieList.size();
    }
    QVariant data (const QModelIndex& index, int role = Qt::DisplayRole) const
    {
            std::vector<Movie> data = WL.movieList;
            if (role == Qt::DisplayRole)
                return QVariant(data[index.row()].getTitle().c_str());
            return QVariant();
     }
    void remove_data(int index) {
            beginRemoveRows(QModelIndex(), index, index+1);
            WL.movieList.erase(WL.movieList.begin() + index);
            endRemoveRows();
    }
};

#endif // DATAMODEL_H
