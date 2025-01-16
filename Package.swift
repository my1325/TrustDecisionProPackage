// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "TrustDecisionPro",
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "TrustDecisionPro",
            targets: ["TDMobRisk", "TDCorePlugin", "FMDeviceManagerFramework"]
        ),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .binaryTarget(
            name: "TDMobRisk",
            path: "Frameworks/TDMobRisk.xcframework"
        ),
        .binaryTarget(
            name: "TDCorePlugin",
            path: "Frameworks/TDCorePlugin.xcframework"
        ),
        .binaryTarget(
            name: "FMDeviceManagerFramework",
            path: "Frameworks/FMDeviceManagerFramework.xcframework"
        ),
    ]
)
