#ifndef DRIVETYPE_H
#define DRIVETYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DriveTypeObject;
class QJsonArray;


class T_MODEL_EXPORT DriveType : public TAbstractModel
{
public:
    DriveType();
    DriveType(const DriveType &other);
    DriveType(const DriveTypeObject &object);
    ~DriveType();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    DriveType &operator=(const DriveType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static DriveType create(const QString &name);
    static DriveType create(const QVariantMap &values);
    static DriveType get(int id);
    static int count();
    static QList<DriveType> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<DriveTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const DriveType &model);
    friend QDataStream &operator>>(QDataStream &ds, DriveType &model);
};

Q_DECLARE_METATYPE(DriveType)
Q_DECLARE_METATYPE(QList<DriveType>)

#endif // DRIVETYPE_H
