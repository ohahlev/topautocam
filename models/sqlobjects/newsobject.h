#ifndef NEWSOBJECT_H
#define NEWSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT NewsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString title;
    QString subline;
    QString status;
    QString line1;
    QString line2;
    QString line3;
    QDateTime created_at;
    QDateTime updated_at;

    enum PropertyIndex {
        Id = 0,
        Title,
        Subline,
        Status,
        Line1,
        Line2,
        Line3,
        CreatedAt,
        UpdatedAt,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("news"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString subline READ getsubline WRITE setsubline)
    T_DEFINE_PROPERTY(QString, subline)
    Q_PROPERTY(QString status READ getstatus WRITE setstatus)
    T_DEFINE_PROPERTY(QString, status)
    Q_PROPERTY(QString line1 READ getline1 WRITE setline1)
    T_DEFINE_PROPERTY(QString, line1)
    Q_PROPERTY(QString line2 READ getline2 WRITE setline2)
    T_DEFINE_PROPERTY(QString, line2)
    Q_PROPERTY(QString line3 READ getline3 WRITE setline3)
    T_DEFINE_PROPERTY(QString, line3)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
};

#endif // NEWSOBJECT_H
