#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_part_admin_form_newView : public TActionView
{
  Q_OBJECT
public:
  partial_part_admin_form_newView() : TActionView() { }
  QString toString();
};

QString partial_part_admin_form_newView::toString()
{
  responsebody.reserve(2172);
  responsebody += QStringLiteral("<div class=\"modal modal-primary\" id=\"newPartModal\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"newPartModalLabel\">\n  <div class=\"modal-dialog modal-lg animated zoomIn animated-3x\" role=\"document\">\n    <div class=\"modal-content\">\n      <div class=\"modal-header\">\n        <h3 class=\"modal-title color-secondary\" id=\"newPartModalLabel\">New Part</h3>\n        <!--\n        <button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\"><span aria-hidden=\"true\"><i class=\"zmdi zmdi-close\"></i></span></button>\n        -->\n      </div>\n      <div class=\"modal-body\">\n        <form class=\"form-horizontal\">\n          <fieldset class=\"container\">\n            <div class=\"form-group row is-empty\">\n              <label for=\"inputEmail\" autocomplete=\"false\" class=\"col-lg-2 control-label\">Name</label>\n              <div class=\"col-lg-9\">\n                <input type=\"text\" class=\"form-control\" id=\"inputName\" placeholder=\"Name\">\n              </div>\n            </div>\n            <div class=\"form-group row is-empty\">\n              <label for=\"inputFile\" class=\"col-lg-2 control-label\">Logo</label>\n              <div class=\"col-lg-9\">\n                <input type=\"text\" readonly=\"\" class=\"form-control\" placeholder=\"Browse...\">\n                <input type=\"file\" id=\"inputFile\" multiple=\"\">\n              </div>\n            </div>\n            <div class=\"form-group row justify-content-end\">\n            \n              <div class=\"col-lg-10\">\n                <button type=\"submit\" class=\"btn btn-raised btn-primary\">Save</button>\n                <button type=\"button\" class=\"btn btn-danger\" data-dismiss=\"modal\">Cancel</button>\n              </div>\n            </div>\n          </fieldset>\n        </form>\n      </div>\n      <!--\n      <div class=\"modal-footer\">\n        <button type=\"button\" class=\"btn btn-danger\" data-dismiss=\"modal\">Save</button>\n        <button type=\"button\" class=\"btn  btn-primary\">Save changes</button>\n      </div>\n      -->\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_part_admin_form_newView)

#include "partial_part_admin_form_newView.moc"
