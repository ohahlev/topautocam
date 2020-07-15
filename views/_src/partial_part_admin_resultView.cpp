#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "colorvalidator.h"
#include "drivetypevalidator.h"
#include "fueltypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"
#include "vehiclevalidator.h"

class T_VIEW_EXPORT partial_part_admin_resultView : public TActionView
{
  Q_OBJECT
public:
  partial_part_admin_resultView() : TActionView() { }
  QString toString();
};

QString partial_part_admin_resultView::toString()
{
  responsebody.reserve(989);
  responsebody += QStringLiteral("<div class=\"panel panel-primary\">\n  <div class=\"panel-heading\">\n    <h3 class=\"panel-title\">\n      <a href=\"javascript:void(0)\" class=\"btn-circle btn-circle-raised btn-circle-danger float-right\" \n      data-toggle=\"modal\" data-target=\"#newPartModal\">\n        <i class=\"fa fa-plus\" style=\"margin-left: 10px\"></i>\n      </a>\n      <i class=\"fa fa-globe\"></i> Part Management\n    </h3>\n  </div>\n  <div class=\"panel-body\">\n    <div class=\"row\" id=\"Container\">\n      ");
  responsebody += QVariant(renderPartial("part_admin")).toString();
  responsebody += QStringLiteral("\n    </div>\n    <div class=\"row\">\n      <div class=\"col-lg-3\">\n        ");
  responsebody += QVariant(renderPartial("pager")).toString();
  responsebody += QStringLiteral("\n      </div>\n    </div>\n  </div>\n</div>\n\n");
  responsebody += QVariant(renderPartial("part_admin_form_new")).toString();
  responsebody += QStringLiteral("\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_part_admin_resultView)

#include "partial_part_admin_resultView.moc"
