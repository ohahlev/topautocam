#include <QtCore>
#include <TreeFrogView>
#include "bodytype.h" 
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

class T_VIEW_EXPORT bodytype_createView : public TActionView
{
  Q_OBJECT
public:
  bodytype_createView() : TActionView() { }
  QString toString();
};

QString bodytype_createView::toString()
{
  responsebody.reserve(2835);
    tfetch(QVariantMap, bodyType);
  tfetch(QString, err_name);
  responsebody += QStringLiteral("<div class=\"container\">\n    <div class=\"row\">\n        <div class=\"col-lg-12\">\n            <div class=\"panel panel-primary\">\n                <div class=\"panel-heading\">\n                    <h3 class=\"panel-title\">\n                        <i class=\"fa fa-globe\"></i>\n                        Create Body\n                    </h3>\n                </div>\n                <div class=\"panel-body\">\n                    ");
  responsebody += QVariant(renderPartial("error")).toString();
  responsebody += QStringLiteral("\n                    <form class=\"form-horizontal\" method=\"POST\" action=\"/admin/body/create\">\n                        <fieldset class=\"container\">\n                            <div class=\"form-group row is-empty\">\n                                <label for=\"inputName\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Name</label>\n                                <div class=\"col-lg-10\">\n                                    ");
  if(err_name == NULL) {
  responsebody += QStringLiteral("                                        <input type=\"text\" class=\" form-control is-valid\" id=\"inputName\" placeholder=\"name\" name=\"bodyType[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(bodyType["name"]);
  responsebody += QStringLiteral("\"/>\n                                    ");
  } else {
  responsebody += QStringLiteral("                                        <input type=\"text\" class=\"form-control is-invalid\" id=\"inputName\" placeholder=\"name\" name=\"bodyType[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(bodyType["name"]);
  responsebody += QStringLiteral("\"/>\n                                        <div class=\"invalid-feedback\">\n                                            ");
  responsebody += THttpUtility::htmlEscape(err_name);
  responsebody += QStringLiteral("\n                                        </div>\n                                    ");
  };
  responsebody += QStringLiteral("                                </div>\n                            </div>\n                            <div class=\"form-group row\">\n                                <div class=\"col-lg-10\">\n                                    <button type=\"submit\" class=\"btn btn-raised btn-danger\">Create</button>\n                                    <a href=\"");
  responsebody += QVariant(urla("index")).toString();
  responsebody += QStringLiteral("\" class=\"btn btn-raised btn-info\">Cancel</a>\n                                </div>\n                            </div>\n                        </fieldset>\n                    </form>\n                </div>\n            </div>\n        </div>\n    </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(bodytype_createView)

#include "bodytype_createView.moc"
