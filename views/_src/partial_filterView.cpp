#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_filterView : public TActionView
{
  Q_OBJECT
public:
  partial_filterView() : TActionView() { }
  QString toString();
};

QString partial_filterView::toString()
{
  responsebody.reserve(4115);
  responsebody += QStringLiteral("<div class=\"card card-primary\">\n  <div class=\"card-header\">\n    <h3 class=\"card-title\"><i class=\"zmdi zmdi-filter-list\"></i>Filter List</h3>\n  </div>\n  <div class=\"card-body no-pb\">\n    <form class=\"form-horizontal\">\n      <h4 class=\"no-m color-primary\">Categories</h4>\n      \n      <div class=\"form-group mt-1\">\n          <input id=\"search-box-slidebar\" type=\"text\" class=\"search-input\" placeholder=\"Search...\" name=\"q\">\n          <label for=\"search-box-slidebar\"><i class=\"zmdi zmdi-search\"></i></label>\n      </div>\n\n      <div class=\"form-group mt-1\">\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios0\" value=\"option0\" checked=\"\" class=\"filter active\" data-filter=\"all\"><span class=\"circle\"></span><span class=\"check\"></span> All </label>\n        </div>\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios1\" value=\"option1\" class=\"filter\" data-filter=\".category-1\"><span class=\"circle\"></span><span class=\"check\"></span> Category One </label>\n        </div>\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios2\" value=\"option2\" class=\"filter\" data-filter=\".category-2\"><span class=\"circle\"></span><span class=\"check\"></span> Category Two </label>\n        </div>\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios3\" value=\"option3\" class=\"filter\" data-filter=\".category-3\"><span class=\"circle\"></span><span class=\"check\"></span> Category Three </label>\n        </div>\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios4\" value=\"option4\" class=\"filter\" data-filter=\".category-4\"><span class=\"circle\"></span><span class=\"check\"></span> Category Four </label>\n        </div>\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios5\" value=\"option5\" class=\"filter\" data-filter=\".category-5\"><span class=\"circle\"></span><span class=\"check\"></span> Category Five </label>\n        </div>\n        <div class=\"radio no-mb\">\n          <label>\n            <input type=\"radio\" name=\"optionsRadios\" id=\"optionsRadios6\" value=\"option6\" class=\"filter\" data-filter=\".category-6\"><span class=\"circle\"></span><span class=\"check\"></span> Category Six </label>\n        </div>\n      </div>\n    </form>\n    <h4 class=\"mt-2 color-primary no-mb\">Columns</h4>\n  </div>\n  <ul class=\"nav nav-tabs nav-tabs-transparent indicator-primary nav-tabs-full nav-tabs-4\" role=\"tablist\">\n    <li class=\"nav-item\"><a id=\"Cols1\" class=\"nav-link withoutripple\" href=\"#home7\" aria-controls=\"home7\" role=\"tab\" data-toggle=\"tab\">1</a></li>\n    <li class=\"nav-item\"><a id=\"Cols2\" class=\"nav-link withoutripple\" href=\"#profile7\" aria-controls=\"profile7\" role=\"tab\" data-toggle=\"tab\">2</a></li>\n    <li class=\"nav-item\"><a id=\"Cols3\" class=\"nav-link active withoutripple\" href=\"#messages7\" aria-controls=\"messages7\" role=\"tab\" data-toggle=\"tab\">3</a></li>\n    <li class=\"nav-item\"><a id=\"Cols4\" class=\"nav-link withoutripple\" href=\"#settings7\" aria-controls=\"settings7\" role=\"tab\" data-toggle=\"tab\">4</a></li>\n    <span id=\"i2\" class=\"ms-tabs-indicator\" style=\"left: 127.5px; width: 63.75px;\"></span></ul>\n  <div class=\"card-body pr-0\">\n    <form class=\"form-horizontal\">\n      <div class=\"form-group no-mt\">\n        <h4 class=\"no-m color-primary mb-2\">Descriptions</h4>\n        <div class=\"togglebutton\">\n          <label>\n            <input id=\"port-show\" type=\"checkbox\"><span class=\"toggle\"></span> Show description </label>\n        </div>\n      </div>\n    </form>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_filterView)

#include "partial_filterView.moc"
