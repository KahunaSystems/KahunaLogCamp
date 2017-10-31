
Pod::Spec.new do |s|

  s.name         = "LogCamp"
  s.version      = "3.2.7"
  s.summary      = "LogCamp for Kahuna Logger Library"

  s.description  = <<-DESC
                   LogCamp is used to manage 1. Analytics 2. Session 3. Logs 4. App Distributions and many more
		    DESC

  s.homepage     = "https://github.com/PrasadPotale/KahunaLogCamp/blob/master/README.md"

  s.license      = 'MIT'

  s.author             = { "PrasadPotale" => "prasadpotale@gmail.com" }

  s.platform     = :ios, "5.0"

  s.source       = { :git => "https://github.com/PrasadPotale/KahunaLogCamp.git", :tag => "#{s.version}" }

  s.frameworks = 'SystemConfiguration', 'CoreTelephony', 'CoreGraphics'

  s.vendored_frameworks = 'LogCamp.framework'
  
  # s.resources = "LogCamp.framework/*.plist"

  s.public_header_files = "LogCamp.framework/Headers/**/*.h"

  s.libraries = 'z'

  s.requires_arc = true

  s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
  
  s.dependency 'PLCrashReporter-DynamicFramework'
  	
end
