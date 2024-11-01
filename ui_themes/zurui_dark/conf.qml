pragma Singleton
import QtQuick
import QtQuick.Window

/*
 * Singleton configuration object for application-wide UI properties.
 * This object provides standardized properties such as background color,
 * font color, and a responsive UI scale factor based on screen resolution.
 *
 * The properties are organized into different sections for easier management
 * and usage across the application. The following sections are included:
 *
 * - app_props: General application properties.
 * - sign_up_props: Properties related to the sign-up interface.
 * - sign_in_props: Properties related to the sign-in interface.
 * - zurui: General properties for the Zurui application.
 *
 * Each section contains relevant properties to enhance modularity and clarity
 * within the application's codebase.
 */
QtObject {
    /*
     * Application properties that define general UI settings.
     */
    property var app_props: QtObject {
        // Theme's name (note: theme's name must be same as its folder name).
        property string theme_name: "zurui_dark"

        // Indicates whether assets should be preloaded at the start.
        property bool assets_preloading: true

        // Application background color in hexadecimal format (default: black).
        property string app_bg_color: "black"

        // Application font color in hexadecimal format (default: white).
        property string app_font_color: "#FFFFFF"
    }

    /*
     * Properties related to the sign-up interface.
     */
    property var sign_up_props: QtObject {
        // Indicates whether the background should be animated (video) or static (image).
        property bool bg_animated: true

        // File path for the background source during sign-up.
        property string bg_source: "assets/plana-blue-archive-moewalls-com.mp4"
    }

    /*
     * Properties related to the sign-in interface.
     */
    property var sign_in_props: QtObject {
        // Indicates whether the background should be animated (video) or static (image).
        property bool bg_animated: true

        // File path for the background source during sign-in.
        property string bg_source: "assets/plana-blue-archive-moewalls-com.mp4"
    }

    /*
     * General properties for the Zurui application.
     */
    property var zurui: QtObject {
        // Indicates whether the background should be animated (video) or static (image).
        property bool bg_animated: true

        // File path for the background source for the Zurui main screen.
        property string bg_source: "assets/plana-blue-archive-moewalls-com.mp4"
    }

    /*
     * Reference screen resolution dimensions used as the baseline for scaling.
     * These dimensions represent a 1920x1080 (1080p) screen.
     */
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
