import QtQuick
import QtQuick.Window

pragma Singleton

/*
 * Singleton configuration object for application-wide UI properties.
 * This object provides standardized properties such as background color,
 * font color, and a responsive UI scale factor based on screen resolution.
 */
QtObject {
    // Application background color in hexadecimal format (default: dark blue).
    property string app_bg_color: "#070F2B"

    // Application font color in hexadecimal format (default: white).
    property string app_font_color: "#FFFFFF"

    /*
     * Reference screen resolution dimensions, used as the baseline
     * for scaling. These dimensions represent a 1920x1080 (1080p) screen.
     * Adjust these values if a different baseline resolution is needed.
     */
    property int referenceWidth: 1920
    property int referenceHeight: 1080

    /*
     * UI scale factor based on screen dimensions, ensuring consistent
     * UI scaling across different screen resolutions. It is calculated
     * as the ratio of the current screen dimensions to the baseline
     * 1920x1080 resolution, with adjustments for aspect ratio.
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
