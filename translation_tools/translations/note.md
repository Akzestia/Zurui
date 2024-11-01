## Translation Management

### Generating Translation Files

We use Qt's `lupdate` tool to generate translation files for multiple languages. The tool scans the source code for translatable strings and updates the `.ts` files accordingly.

#### Supported Languages
- English (en)
- Ukrainian (ua)
- Japanese (ja)

#### Generate Translation Files
Run the following command from the project root:
```bash
lupdate . -recursive -ts \
    translation_tools/translations/translations_ua.ts \
    translation_tools/translations/translations_ja.ts \
    translation_tools/translations/translations_en.ts
