# LiveTranslate
This sample app demonstrates how to get live translation in C++ based apps similar to that provided by the Retranslate class in QML, using only a few lightweight C++ classes.

The core of this method is the LiveTranslator class, which is attached to each control attribute in your UI you wish to be dynamically translated, and which updates those strings via slots on the controls. Several "helper" classes also allow live translation of UI controls which don't use Qt slots to set string attributes.

Note that since this example includes live translation of bb::system::SystemDialog, which requires the use of SystemDialog::update(), this code must be compiled with API 10.2 or higher as that function wasn't added till that API level. If your app doesn't require live translation of SystemDialog or its brethren then you can use LiveTranslator with any API level.