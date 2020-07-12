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

class T_VIEW_EXPORT dashboard_indexView : public TActionView
{
  Q_OBJECT
public:
  dashboard_indexView() : TActionView() { }
  QString toString();
};

QString dashboard_indexView::toString()
{
  responsebody.reserve(2401);
  responsebody += QStringLiteral("<div class=\"wrap bg-warning color-dark\">\n  <div class=\"container\">\n    <!--\n    <h1 class=\"color-white text-center mb-4\">Some numerical data</h1>\n    -->\n    <div class=\"row\">\n      <div class=\"col-xl-3 col-md-6\">\n        <div class=\"card card-royal card-body overflow-hidden text-center wow zoomInUp animation-delay-2\" style=\"visibility: visible; animation-name: zoomInUp;\">\n          <h2 class=\"counter\">123</h2>\n          <i class=\"fa fa-4x fa-car color-royal\"></i>\n          <p class=\"mt-2 no-mb lead small-caps\">vehicles</p>\n        </div>\n      </div>\n      <div class=\"col-xl-3 col-md-6\">\n        <div class=\"card card-success card-body overflow-hidden text-center wow zoomInUp animation-delay-5\" style=\"visibility: visible; animation-name: zoomInUp;\">\n          <h2 class=\"counter\">232</h2>\n          <i class=\"fa fa-4x fa-briefcase color-success\"></i>\n          <p class=\"mt-2 no-mb lead small-caps\">parts</p>\n        </div>\n      </div>\n      <div class=\"col-xl-3 col-md-6\">\n        <div class=\"card card-danger card-body overflow-hidden text-center wow zoomInUp animation-delay-4\" style=\"visibility: visible; animation-name: zoomInUp;\">\n          <h2 class=\"counter\">3</h2>\n          <i class=\"fa fa-4x fa-comments-o color-danger\"></i>\n          <p class=\"mt-2 no-mb lead small-caps\">services</p>\n        </div>\n      </div>\n      <div class=\"col-xl-3 col-md-6\">\n        <div class=\"card card-info card-body overflow-hidden text-center wow zoomInUp animation-delay-3\" style=\"visibility: visible; animation-name: zoomInUp;\">\n          <h2 class=\"counter\">5</h2>\n          <i class=\"fa fa-4x fa-group color-info\"></i>\n          <p class=\"mt-2 no-mb lead small-caps\">jobs</p>\n        </div>\n      </div>\n    </div>\n    <!--\n    <div class=\"text-center color-white mw-800 center-block mt-4\">\n      <p class=\"lead lead-lg\">Discover our projects and the rigorous process of creation. Our principles are creativity, design, experience and knowledge. We are backed by 20 years of research.</p>\n      <a href=\"javascript:void(0)\" class=\"btn btn-raised btn-white color-info wow flipInX animation-delay-8\" style=\"visibility: visible; animation-name: flipInX;\"><i class=\"fa fa-space-shuttle\"></i> I have a project</a>\n    </div>\n    -->\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(dashboard_indexView)

#include "dashboard_indexView.moc"
