#ifndef GRADE_H
#define GRADE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class GradeObject;
class QJsonArray;


class T_MODEL_EXPORT Grade : public TAbstractModel
{
public:
    Grade();
    Grade(const Grade &other);
    Grade(const GradeObject &object);
    ~Grade();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    Grade &operator=(const Grade &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Grade create(const QString &name);
    static Grade create(const QVariantMap &values);
    static Grade get(int id);
    static int count();
    static QList<Grade> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<GradeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Grade &model);
    friend QDataStream &operator>>(QDataStream &ds, Grade &model);
};

Q_DECLARE_METATYPE(Grade)
Q_DECLARE_METATYPE(QList<Grade>)

#endif // GRADE_H
