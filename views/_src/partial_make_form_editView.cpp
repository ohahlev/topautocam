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

class T_VIEW_EXPORT partial_make_form_editView : public TActionView
{
  Q_OBJECT
public:
  partial_make_form_editView() : TActionView() { }
  QString toString();
};

QString partial_make_form_editView::toString()
{
  responsebody.reserve(2177);
  responsebody += QStringLiteral("<div class=\"modal modal-primary\" id=\"editMakeModal\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"editMakeModalLabel\">\n  <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n    <div class=\"modal-content\">\n      <div class=\"modal-header\">\n        <h3 class=\"modal-title color-secondary\" id=\"editMakeModalLabel\">Edit Make</h3>\n        <!--\n        <button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\"><span aria-hidden=\"true\"><i class=\"zmdi zmdi-close\"></i></span></button>\n        -->\n      </div>\n      <div class=\"modal-body\">\n        <form class=\"form-horizontal\">\n          <fieldset class=\"container\">\n            <div class=\"form-group row is-empty\">\n              <label for=\"inputEmail\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Name</label>\n              <div class=\"col-lg-9\">\n                <input type=\"text\" class=\"form-control\" id=\"inputName\" placeholder=\"Name\">\n              </div>\n            </div>\n            <div class=\"form-group row is-empty\">\n              <label for=\"inputFile\" class=\"col-lg-2 control-label\">Logo</label>\n              <div class=\"col-lg-10\">\n                <input type=\"text\" readonly=\"\" class=\"form-control\" placeholder=\"Browse...\">\n                <input type=\"file\" id=\"inputFile\" multiple=\"\">\n              </div>\n            </div>\n            <div class=\"form-group row justify-content-end\">\n            \n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-primary\">Save</button>\n                <button type=\"button\" class=\"btn btn-danger\" data-dismiss=\"modal\">Cancel</button>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n      <!--\n      <div class=\"modal-footer\">\n        <button type=\"button\" class=\"btn btn-danger\" data-dismiss=\"modal\">Save</button>\n        <button type=\"button\" class=\"btn  btn-primary\">Save changes</button>\n      </div>\n      -->\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_make_form_editView)

#include "partial_make_form_editView.moc"
