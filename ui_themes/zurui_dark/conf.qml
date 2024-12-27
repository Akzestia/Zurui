pragma Singleton
import QtQuick
import QtQuick.Window

/*
 * Singleton configuration object for application-wide UI properties.
 * This object provides standardized properties such as background color,
 * font color, and a responsive UI scale factor based on screen resolution.
 *
 * Each section contains relevant properties to enhance modularity and clarity
 * within the application's codebase.
 */

QtObject {
    property var app_props: QtObject {
        property string theme_name: "zurui_dark"
        property bool assets_preloading: true
        property string app_bg_color: "#000000"
        property string app_font_color: "#ffffff"

        //Customize the color of workspaces background
        //Use hex values for colors
        //Note that if u want to have a semi-trsnparent bg, use argb (#82|00|00|00) instead of rgb (#00|00|00)
        property string workspace_argb_color: "#82000000"
        property string workspace_argb_border_color: "#FFFFFF"

        property string password_charcter: "*"
        property real password_mask_delay: 100
    }

    property var animation_props: QtObject {
        property real surface_switch_duration: 450
        property real surface_opacity_duration: 450
    }

    property var auth_window_props: QtObject {
        property bool bg_animated: true
        property string animated_bg_source: Qt.resolvedUrl("assets/tendou-alice-blue-archive-moewalls-com.mp4")
        property string static_bg_source: Qt.resolvedUrl("assets/EngageKiss.png")

        property string sign_in_bg_color: "#88000000"
        property real sign_in_frame_radius: 20
        property string sign_in_user_name_input_text_color: "cyan"
        property string sign_in_password_input_text_color: "cyan"
        //1st & 2nd part of the "go to sign up" label
        property string sign_in_switch_label_text_color: "#FFFFFF"
        //Color when hovering on the 2nd part of the label
        property string sign_in_switch_label_hover_text_color: "cyan"

        property string sign_up_bg_color: "#88000000"
        property real sign_up_frame_radius: 10
        property string sign_up_user_name_input_text_color: "cyan"
        property string sign_up_user_name_input_placeholder_text_color: "cyan"
        property string sign_up_user_email_input_text_color: "cyan"
        property string sign_up_user_email_input_placeholder_text_color: "cyan"
        property string sign_up_password_input_text_color: "cyan"
        property string sign_up_password_input_placeholder_text_color: "cyan"
        property string sign_up_re_password_input_text_color: "cyan"
        property string sign_up_re_password_input_placeholder_text_color: "cyan"
        //1st & 2nd part of the "go to sign up" label
        property string sign_up_switch_label_text_color: "#FFFFFF"
        //Color when hovering on the 2nd part of the label
        property string sign_up_switch_label_hover_text_color: "cyan"
    }

    property var main_window_props: QtObject {
        property bool bg_animated: true
        property string bg_source: Qt.resolvedUrl("assets/plana-blue-archive-moewalls-com.mp4")
    }

    property int referenceWidth: 1920
    property int referenceHeight: 1080

    /*
     * UI scale factor based on current screen dimensions, ensuring consistent
     * UI scaling across different screen resolutions. It is calculated as the
     * ratio of the current screen dimensions to the baseline resolution.
     *
     * - If the screen is exactly 1920x1080, the scale factor will be 1.0.
     * - If the screen is smaller, the scale factor will be less than 1.0.
     * - If the screen is larger, the scale factor will be greater than 1.0.
     * - Scaling adapts to the smaller dimension (either width or height),
     *   preserving aspect ratio.
     *
     * Example:
     *  - On a 1440p screen (2560x1440), `app_ui_scale_factor` will be ~1.33.
     *  - On a 720p screen (1280x720), `app_ui_scale_factor` will be ~0.67.
     */
    property real app_ui_scale_factor: {
        let screenWidth = Screen.width;
        let screenHeight = Screen.height;
        return Math.min(screenWidth / referenceWidth, screenHeight / referenceHeight);
    }
}
