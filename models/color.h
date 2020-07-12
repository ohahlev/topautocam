#ifndef COLOR_H
#define COLOR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ColorObject;
class QJsonArray;


class T_MODEL_EXPORT Color : public TAbstractModel
{
public:
    Color();
    Color(const Color &other);
    Color(const ColorObject &object);
    ~Color();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    Color &operator=(const Color &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Color create(const QString &name);
    static Color create(const QVariantMap &values);
    static Color get(int id);
    static int count();
    static QList<Color> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ColorObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Color &model);
    friend QDataStream &operator>>(QDataStream &ds, Color &model);
};

Q_DECLARE_METATYPE(Color)
Q_DECLARE_METATYPE(QList<Color>)

#endif // COLOR_H
