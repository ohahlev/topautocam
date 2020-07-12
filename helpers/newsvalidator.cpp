#include "newsvalidator.h"

NewsValidator::NewsValidator() : TFormValidator()
{
    // title
    setRule("title", Tf::Required, true, "title is required");
    setRule("title", Tf::MaxLength, 1024, "title max length is 64");

    // subline
    setRule("subline", Tf::Required, true, "subline is required");
    setRule("subline", Tf::MaxLength, 1024, "subline max length is 128");

    // status
    setRule("status", Tf::Required, true, "status is required");

    // line1
    setRule("line1", Tf::Required, true, "line1 is required");
    setRule("line1", Tf::MaxLength, 1024, "line1 max length is 64");

    // line2
    setRule("line2", Tf::Required, true, "line2 is required");
    setRule("line2", Tf::MaxLength, 1024, "line2 max length is 64");

    // line3
    setRule("line3", Tf::Required, true, "line3 is required");
    setRule("line3", Tf::MaxLength, 1024, "line3 max length is 64");
}
