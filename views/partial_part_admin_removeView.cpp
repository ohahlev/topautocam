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

class T_VIEW_EXPORT partial_part_admin_removeView : public TActionView
{
  Q_OBJECT
public:
  partial_part_admin_removeView() : TActionView() { }
  QString toString();
};

QString partial_part_admin_removeView::toString()
{
  responsebody.reserve(1584);
  responsebody += QStringLiteral("<div class=\"modal modal-danger\" id=\"removePartModal\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"removePartModalLabel\">\n  <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n    <div class=\"modal-content\">\n      <div class=\"modal-header\">\n        <h3 class=\"modal-title color-secondary\" id=\"removePartModalLabel\">Remove Part</h3>\n        <!--\n        <button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\"><span aria-hidden=\"true\"><i class=\"zmdi zmdi-close\"></i></span></button>\n        -->\n      </div>\n      <div class=\"modal-body\">\n        <form class=\"form-horizontal\">\n          <fieldset class=\"container\">\n            <div class=\"form-group row\">\n               <div class=\"col-lg-10\">\n                <h3>Are you sure to remove?</h3>\n              </div>\n            </div>\n            <div class=\"form-group row\">\n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-danger\">Yes</button>\n                <button type=\"button\" class=\"btn btn-primary\" data-dismiss=\"modal\">No</button>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n      <!--\n      <div class=\"modal-footer\">\n        <button type=\"button\" class=\"btn btn-danger\" data-dismiss=\"modal\">Save</button>\n        <button type=\"button\" class=\"btn  btn-primary\">Save changes</button>\n      </div>\n      -->\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_part_admin_removeView)

#include "partial_part_admin_removeView.moc"
