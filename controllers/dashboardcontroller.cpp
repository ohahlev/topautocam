#include "dashboardcontroller.h"
#include "user.h"

void DashboardController::index()
{
    render("index", "backend");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DashboardController)
