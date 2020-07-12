#ifndef VEHICLEOBJECT_H
#define VEHICLEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VehicleObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString title;
    QString detail;
    QString code;
    QString frame_no;
    QDateTime manufacturing_date;
    QDateTime deposit_date;
    QString engine;
    QString mileage;
    QDateTime created_at;
    QDateTime updated_at;
    QString vehicle_status;
    QString inventory_status;
    double price {0};
    int make_id {0};
    int model_id {0};
    int color_id {0};
    int grade_id {0};
    int drive_id {0};
    int fuel_id {0};
    int body_id {0};

    enum PropertyIndex {
        Id = 0,
        Title,
        Detail,
        Code,
        FrameNo,
        ManufacturingDate,
        DepositDate,
        Engine,
        Mileage,
        CreatedAt,
        UpdatedAt,
        VehicleStatus,
        InventoryStatus,
        Price,
        MakeId,
        ModelId,
        ColorId,
        GradeId,
        DriveId,
        FuelId,
        BodyId,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("vehicle"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString detail READ getdetail WRITE setdetail)
    T_DEFINE_PROPERTY(QString, detail)
    Q_PROPERTY(QString code READ getcode WRITE setcode)
    T_DEFINE_PROPERTY(QString, code)
    Q_PROPERTY(QString frame_no READ getframe_no WRITE setframe_no)
    T_DEFINE_PROPERTY(QString, frame_no)
    Q_PROPERTY(QDateTime manufacturing_date READ getmanufacturing_date WRITE setmanufacturing_date)
    T_DEFINE_PROPERTY(QDateTime, manufacturing_date)
    Q_PROPERTY(QDateTime deposit_date READ getdeposit_date WRITE setdeposit_date)
    T_DEFINE_PROPERTY(QDateTime, deposit_date)
    Q_PROPERTY(QString engine READ getengine WRITE setengine)
    T_DEFINE_PROPERTY(QString, engine)
    Q_PROPERTY(QString mileage READ getmileage WRITE setmileage)
    T_DEFINE_PROPERTY(QString, mileage)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(QString vehicle_status READ getvehicle_status WRITE setvehicle_status)
    T_DEFINE_PROPERTY(QString, vehicle_status)
    Q_PROPERTY(QString inventory_status READ getinventory_status WRITE setinventory_status)
    T_DEFINE_PROPERTY(QString, inventory_status)
    Q_PROPERTY(double price READ getprice WRITE setprice)
    T_DEFINE_PROPERTY(double, price)
    Q_PROPERTY(int make_id READ getmake_id WRITE setmake_id)
    T_DEFINE_PROPERTY(int, make_id)
    Q_PROPERTY(int model_id READ getmodel_id WRITE setmodel_id)
    T_DEFINE_PROPERTY(int, model_id)
    Q_PROPERTY(int color_id READ getcolor_id WRITE setcolor_id)
    T_DEFINE_PROPERTY(int, color_id)
    Q_PROPERTY(int grade_id READ getgrade_id WRITE setgrade_id)
    T_DEFINE_PROPERTY(int, grade_id)
    Q_PROPERTY(int drive_id READ getdrive_id WRITE setdrive_id)
    T_DEFINE_PROPERTY(int, drive_id)
    Q_PROPERTY(int fuel_id READ getfuel_id WRITE setfuel_id)
    T_DEFINE_PROPERTY(int, fuel_id)
    Q_PROPERTY(int body_id READ getbody_id WRITE setbody_id)
    T_DEFINE_PROPERTY(int, body_id)
};

#endif // VEHICLEOBJECT_H
