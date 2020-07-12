#include "dashboardcontroller.h"
#include "user.h"

bool DashboardController::preFilter()
{
    if (!isUserLoggedIn()) {
        redirect(url("admin/user", "login"));
        return false;
    }
    return true;
}

void DashboardController::index()
{
    render("index", "backend");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DashboardController)
