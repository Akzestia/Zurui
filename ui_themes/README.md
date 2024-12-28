# Configuration Layout for Theme configuration files 

## Table of Contents
1. [Complete Layout](#complete-layout)
2. [App Properties](#app-properties) 
3. [Animation Properties](#animation-properties) 
4. [Authentication Window Properties](#authentication-window-properties) 
5. [Main Window Properties](#main-window-properties) 
6. [Application UI Scaling Factor](#application-ui-scaling-factor)

### Complete Layout 

```qml
QtObject {
    property var app_props: QtObject {
        property string theme_name: "zurui_dark"
        property bool assets_preloading: true
        property string app_bg_color: "#000000"
        property string app_font_color: "#ffffff"
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
        property string sign_in_switch_label_text_color: "#FFFFFF"
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
        property string sign_up_switch_label_text_color: "#FFFFFF"
        property string sign_up_switch_label_hover_text_color: "cyan"
    }

    property var main_window_props: QtObject {
        property bool bg_animated: true
        property string bg_source: Qt.resolvedUrl("assets/plana-blue-archive-moewalls-com.mp4")
    }

    property int referenceWidth: 1920
    property int referenceHeight: 1080

    property real app_ui_scale_factor: {
        let screenWidth = Screen.width;
        let screenHeight = Screen.height;
        return Math.min(screenWidth / referenceWidth, screenHeight / referenceHeight);
    }
}
```

### App Properties

```qml
property string theme_name: "zurui_dark"
property bool assets_preloading: true
property string app_bg_color: "#000000"
property string app_font_color: "#ffffff"
property string workspace_argb_color: "#82000000"
property string workspace_argb_border_color: "#FFFFFF"

property string password_charcter: "*"
property real password_mask_delay: 100
```

### Animation Properties

```qml
property real surface_switch_duration: 450
property real surface_opacity_duration: 450
```

### Authentication Window Properties

```qml
property bool bg_animated: true
property string animated_bg_source: Qt.resolvedUrl("assets/tendou-alice-blue-archive-moewalls-com.mp4")
property string static_bg_source: Qt.resolvedUrl("assets/EngageKiss.png")

property string sign_in_bg_color: "#88000000"
property real sign_in_frame_radius: 20
property string sign_in_user_name_input_text_color: "cyan"
property string sign_in_password_input_text_color: "cyan"
property string sign_in_switch_label_text_color: "#FFFFFF"
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
property string sign_up_switch_label_text_color: "#FFFFFF"
property string sign_up_switch_label_hover_text_color: "cyan"
```

### Main Window Properties

```qml
property bool bg_animated: true
property string bg_source: Qt.resolvedUrl("assets/plana-blue-archive-moewalls-com.mp4")
```

### Application UI Scaling Factor

```qml
let screenWidth = Screen.width;
let screenHeight = Screen.height;
return Math.min(screenWidth / referenceWidth, screenHeight / referenceHeight);
```
