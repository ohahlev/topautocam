#ifndef VEHICLEGALLERYOBJECT_H
#define VEHICLEGALLERYOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VehicleGalleryObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString photo;
    QDateTime created_at;
    QDateTime updated_at;
    int vehicle_id {0};

    enum PropertyIndex {
        Id = 0,
        Photo,
        CreatedAt,
        UpdatedAt,
        VehicleId,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("vehicle_gallery"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString photo READ getphoto WRITE setphoto)
    T_DEFINE_PROPERTY(QString, photo)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int vehicle_id READ getvehicle_id WRITE setvehicle_id)
    T_DEFINE_PROPERTY(int, vehicle_id)
};

#endif // VEHICLEGALLERYOBJECT_H
