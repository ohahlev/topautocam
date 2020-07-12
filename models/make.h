#ifndef MAKE_H
#define MAKE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MakeObject;
class QJsonArray;


class T_MODEL_EXPORT Make : public TAbstractModel
{
public:
    Make();
    Make(const Make &other);
    Make(const MakeObject &object);
    ~Make();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString logo() const;
    void setLogo(const QString &logo);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    Make &operator=(const Make &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Make create(const QString &name, const QString &logo);
    static Make create(const QVariantMap &values);
    static Make get(int id);
    static int count();
    static QList<Make> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<MakeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Make &model);
    friend QDataStream &operator>>(QDataStream &ds, Make &model);
};

Q_DECLARE_METATYPE(Make)
Q_DECLARE_METATYPE(QList<Make>)

#endif // MAKE_H
