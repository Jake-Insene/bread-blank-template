plugins {
    alias(libs.plugins.android.application)
}

android {
    namespace = "com.example.project_name"
    compileSdk = 35

    defaultConfig {
        applicationId = "com.example.project_name"
        minSdk = 24
        targetSdk = 35
        versionCode = 1
        versionName = "1.0"

        ndk {
            abiFilters += listOf("arm64-v8a", "x86_64")
        }

        externalNativeBuild {
            cmake {
                arguments += "-DBREAD_ANDROID=YES"
            }
        }
    }

    sourceSets {
        getByName("main") {
            java.srcDir("src")
            res.srcDir("res")
            assets.srcDir("../assets")
            manifest.srcFile("AndroidManifest.xml")
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
    externalNativeBuild {
        cmake {
            path = file("../CMakeLists.txt")
            version = "3.22.1"
        }
    }

    ndkVersion = "28.0.13004108"
}

