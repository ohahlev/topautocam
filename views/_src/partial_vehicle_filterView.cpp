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

class T_VIEW_EXPORT partial_vehicle_filterView : public TActionView
{
  Q_OBJECT
public:
  partial_vehicle_filterView() : TActionView() { }
  QString toString();
};

QString partial_vehicle_filterView::toString()
{
  responsebody.reserve(4279);
  responsebody += QStringLiteral("<div class=\"card card-primary\">\n  <div class=\"card-header\">\n    <h3 class=\"card-title\">Filter List</h3>\n  </div>\n  <div class=\"card-body\">\n    <div class=\"row\">\n      <div class=\"col-md-8\">\n        <form class=\"form-horizontal\" id=\"Filters\">\n          <div class=\"row\">\n            <div class=\"col-md-6\">\n              <fieldset>\n                <h4 class=\"mb-1 no-mt\">Devices</h4>\n                <div class=\"form-group no-mt\">\n                  <div class=\"checkbox ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".smartphone\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Smartphones </label>\n                  </div>\n                  <div class=\"checkbox  ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".tablet\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Tablets </label>\n                  </div>\n                  <div class=\"checkbox  ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".laptop\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Laptops </label>\n                  </div>\n                  <div class=\"checkbox  ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".accessory\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Accesories </label>\n                  </div>\n                </div>\n              </fieldset>\n            </div>\n            <div class=\"col-md-6\">\n              <fieldset>\n                <h4 class=\"mb-1\">Brand</h4>\n                <div class=\"form-group no-mt\">\n                  <div class=\"checkbox  ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".apple\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Apple </label>\n                  </div>\n                  <div class=\"checkbox  ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".microsoft\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Microsoft </label>\n                  </div>\n                  <div class=\"checkbox ml-2\">\n                    <label>\n                      <input type=\"checkbox\" value=\".samsung\"><span class=\"checkbox-material\"><span class=\"check\"></span></span> Samsung </label>\n                  </div>\n                </div>\n              </fieldset>\n            </div>\n          </div>\n        </form>\n      </div>\n      <div class=\"col-md-4\">\n        <form class=\"form-horizontal\">\n          <h4>Sort by</h4>\n          <div class=\"dropdown bootstrap-select form-control\">\n            <div class=\"form-group\"><select id=\"SortSelect\" class=\"form-control selectpicker\" tabindex=\"-98\">\n                <option value=\"random\">Popular</option>\n                <option value=\"price:asc\">Price ASC</option>\n                <option value=\"price:desc\">Price DESC</option>\n                <option value=\"date:asc\">Release ASC</option>\n                <option value=\"date:desc\">Release DESC</option>\n              </select></div>\n            <button type=\"button\" class=\"btn dropdown-toggle btn-light\" data-toggle=\"dropdown\" role=\"combobox\" aria-owns=\"bs-select-1\" aria-haspopup=\"listbox\" aria-expanded=\"false\" data-id=\"SortSelect\" title=\"Popular\">\n              <div class=\"filter-option\">\n                <div class=\"filter-option-inner\">\n                  <div class=\"filter-option-inner-inner\">Popular</div>\n                </div>\n              </div>\n            </button>\n            <div class=\"dropdown-menu \">\n              <div class=\"inner show\" role=\"listbox\" id=\"bs-select-1\" tabindex=\"-1\">\n                <ul class=\"dropdown-menu inner show\" role=\"presentation\"></ul>\n              </div>\n            </div>\n          </div>\n        </form>\n        <button class=\"btn btn-danger btn-block no-mb mt-2\" id=\"Reset\"><i class=\"zmdi zmdi-delete\"></i> Clear Filters</button>\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_vehicle_filterView)

#include "partial_vehicle_filterView.moc"
