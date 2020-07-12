#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_part_admin_filterView : public TActionView
{
  Q_OBJECT
public:
  partial_part_admin_filterView() : TActionView() { }
  QString toString();
};

QString partial_part_admin_filterView::toString()
{
  responsebody.reserve(1304);
  responsebody += QStringLiteral("<div class=\"card card-primary\">\n  <div class=\"card-header\">\n    <h3 class=\"card-title\"><i class=\"zmdi zmdi-filter-list\"></i>Filter</h3>\n  </div>\n  <div class=\"card-body no-pb\">\n    <form class=\"form-horizontal\">\n      <div class=\"form-group\" style=\"margin-top: -10px;\">\n        <div class=\"input-group\">\n          <i class=\"fa fa-search\" style=\"margin-right: 20px; margin-top: 10px;\"></i>\n          <input type=\"text\" id=\"addon1\" class=\"form-control\">\n        </div>\n      </div>\n      <div class=\"form-group mt-1\">\n        <div class=\"radio radio-primary\">\n          <label>\n            <input type=\"radio\" name=\"sortDriveType\" id=\"sortById\" value=\"sortById\" checked=\"\"> sort by id\n          </label>\n        </div>\n        <div class=\"radio radio-primary\">\n          <label>\n            <input type=\"radio\" name=\"sortDriveType\" id=\"sortByName\" value=\"sortByName\"> sort by name\n          </label>\n        </div>\n        <!--\n        <div class=\"radio radio-primary\">\n          <label>\n            <input type=\"radio\" name=\"sortMake\" id=\"sortByType\" value=\"sortByType\"> sort by type\n          </label>\n        </div>\n        -->\n      </div>\n    </form>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_part_admin_filterView)

#include "partial_part_admin_filterView.moc"
