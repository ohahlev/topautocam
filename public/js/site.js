function activeNavItem() {
    var url = window.location.pathname;
    $('ul.navbar-nav li.nav-item').each(function () {
        $(this).removeClass('active');
    });
    $('a[href="' + url + '"]').parents('.nav-item').addClass('active');
}

function activeNewsCarouselItem() {
    var item = $('.news-item');
    $(item[0]).addClass("active");
}

function activeNewsGalleryCarouselItem() {
    var item = $('.news-gallery');
    $(item[0]).addClass("active");
}

function initTinyMCE() {
    tinymce.init({
        selector: '.editor',
        entity_encoding: 'named',
        skin: 'bootstrap',
        menubar: false,
        plugins: 'lists, link, image, media, advcode',
        toolbar: 'h1 h2 bold italic strikethrough blockquote bullist numlist forecolor backcolor | link image media | removeformat code',
        setup: editor => {
            // Apply the focus effect
            editor.on("init", () => {
                editor.getContainer().style.transition =
                    "border-color 0.15s ease-in-out, box-shadow 0.15s ease-in-out";
            });
            editor.on("focus", () => {
                (editor.getContainer().style.boxShadow =
                    "0 0 0 .2rem rgba(0, 123, 255, .25)"),
                    (editor.getContainer().style.borderColor = "#80bdff");
            });
            editor.on("blur", () => {
                (editor.getContainer().style.boxShadow = ""),
                    (editor.getContainer().style.borderColor = "");
            });
        }
    });
}

function updateCode() {

    var manufactoringDate = $("#inputManufacturingDate").val();
    var frameNo = $("#inputFrameNo").val();
    $("#inputCode").val(`${manufactoringDate}-${frameNo}`);
}

function initDatePicker() {
    $(".datepicker").datepicker({
        format: 'yyyy-mm-dd',
    }).on('changeDate', function(obj) {
        console.debug(obj);
        if(obj.target.id === "inputManufacturingDate") {
            updateCode();
        }
    });
}

function frameNoChange() {
    $("#inputFrameNo").change(function(){
        updateCode();
    });
}

$(document).ready(function () {
    activeNavItem();
    activeNewsCarouselItem();
    activeNewsGalleryCarouselItem();
    initTinyMCE();
    initDatePicker();
    frameNoChange();
});