#include "backendcontroller.h"

QString SESSION_USER = "user";

void BackendController::index()
{
}

bool BackendController::preFilter()
{
    if (!isUserLoggedIn())
    {

        redirect(url("admin/user", "login"));
        return false;
    }

    //User loginUser = User::getByIdentityKey(username);

    QString currentUser = session().value(SESSION_USER).toString();
    if (currentUser == NULL)
    {
        currentUser = identityKeyOfLoginUser();
        session().insert(SESSION_USER, currentUser);
    }

    texport(currentUser);

    return true;
}

// Don't remove below this line
T_DEFINE_CONTROLLER(BackendController)
