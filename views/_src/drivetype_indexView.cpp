#include <QtCore>
#include <TreeFrogView>
#include "drivetype.h"
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "drivetypevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"

class T_VIEW_EXPORT drivetype_indexView : public TActionView
{
  Q_OBJECT
public:
  drivetype_indexView() : TActionView() { }
  QString toString();
};

QString drivetype_indexView::toString()
{
  responsebody.reserve(5183);
    tfetch(QString, notice);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"panel panel-primary\">\n        <div class=\"panel-heading\">\n          <h3 class=\"panel-title\">\n            <a href=\"/admin/drive/create\" class=\"btn-circle btn-circle-raised btn-circle-danger float-right\">\n              <i class=\"fa fa-plus\" style=\"margin-left: 10px\"></i>\n            </a>\n            <i class=\"fa fa-globe\"></i> Drive Management\n          </h3>\n        </div>\n        <div class=\"panel-body\">\n          ");
  responsebody += QVariant(renderPartial("flash")).toString();
  responsebody += QStringLiteral("\n          <div class=\"row\" id=\"Container\">\n            ");
  tfetch(QList<DriveType>, driveTypeList);
  responsebody += QStringLiteral("            ");
  for (const auto &i : driveTypeList) {
  responsebody += QStringLiteral("              <div class=\"col-lg-4 col-md-6 mix category-2\" style=\"display: inline-block;\" data-bound=\"\">\n                <div class=\"card\">\n                  <figure class=\"ms-thumbnail\">\n                    <img src=\"/img/demo/port3.jpg\" alt=\"\" class=\"img-fluid fixed-height\">\n                    <figcaption class=\"ms-thumbnail-caption text-center\">\n                      <div class=\"ms-thumbnail-caption-content\">\n                        <h4 class=\"ms-thumbnail-caption-title mb-2\">\n                          ");
  responsebody += QVariant(i.name()).toString();
  responsebody += QStringLiteral("\n                        </h4>\n                        <a href=\"/admin/drive/save/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" class=\"btn-circle btn-circle-raised btn-circle-xs mr-1 btn-circle-white color-danger\">\n                          <i class=\"zmdi zmdi-edit\"></i>\n                        </a>\n                        <a href=href=\"javascript:void(0)\" \n          class=\"btn-circle btn-circle-raised btn-circle-xs ml-1 mr-1 btn-circle-white color-warning\"\n          data-toggle=\"modal\" data-target=\"#removeDriveModel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                          <i class=\"zmdi zmdi-delete\"></i>\n                        </a>\n                      </div>\n                    </figcaption>\n                  </figure>\n                  <div class=\"card-body overflow-hidden text-center portfolio-item-caption d-none\">\n                    <h3 class=\"color-primary no-mt\">actions</h3>\n                    <p>here it is</p>\n                  </div>\n                </div>\n              </div>\n              <!-- remove modal -->\n              <div class=\"modal modal-danger\" id=\"removeDriveModel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"removeDriveModelLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n                  <div class=\"modal-content\">\n                    <div class=\"modal-header\">\n                      <h3 class=\"modal-title color-secondary\" id=\"removeDriveModelLabel");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">Remove Drive</h3>\n                    </div>\n                    <div class=\"modal-body\">\n                      <form class=\"form-horizontal\" method=\"POST\" action=\"drive/remove/");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\">\n                        <fieldset class=\"container\">\n                          <div class=\"form-group row\">\n                            <div class=\"col-lg-10\">\n                              <h3>Are you sure to remove this drive?</h3>\n                              <div class=\"card\">\n                                <div class=\"card-body\">\n                                  <h3>\n                                    ");
  responsebody += QVariant(i.name()).toString();
  responsebody += QStringLiteral("\n                                  </h3>\n                                </div>\n                              </div>\n                            </div>\n                          </div>\n                          <div class=\"form-group row\">\n                            <div class=\"col-lg-10\">\n                              <button type=\"submit\" class=\"btn btn-raised btn-danger\">Yes</button>\n                              <button type=\"button\" class=\"btn btn-primary\" data-dismiss=\"modal\">No</button>\n                            </div>\n                          </div>\n                        </fieldset>\n                      </form>\n                    </div>\n                  </div>\n                </div>\n              </div>\n              ");
  };
  responsebody += QStringLiteral("            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(drivetype_indexView)

#include "drivetype_indexView.moc"
