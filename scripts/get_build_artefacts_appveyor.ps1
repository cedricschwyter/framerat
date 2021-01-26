$apiUrl = 'https://ci.appveyor.com/api'
$token = '9ou7lloef1iiwqiuma58'
$headers = @{}
$headers['Authorization'] = "Bearer $token"
$headers["Content-type"] = "application/json"
$accountName = 'D3PSI'
$projectSlug = 'framerat'
$downloadLocation = 'C:\projects\framerat'
$project = Invoke-RestMethod -Method Get -Uri "$apiUrl/projects/$accountName/$projectSlug" -Headers $headers
$jobId = $project.build.jobs[0].jobId
$artifacts = Invoke-RestMethod -Method Get -Uri "$apiUrl/buildjobs/$jobId/artifacts" -Headers $headers
$artifactFileName = $artifacts[0].fileName
$version_appveyor = $env:APPVEYOR_REPO_TAG_NAME
$localArtifactPath = "$downloadLocation\framerat-linux-rolling-$version_appveyor.zip"
Invoke-RestMethod -Method Get -Uri "$apiUrl/buildjobs/$jobId/artifacts/$artifactFileName" `
-OutFile $localArtifactPath -Headers @{ "Authorization" = "Bearer $token" }

$jobId = $project.build.jobs[1].jobId
$artifacts = Invoke-RestMethod -Method Get -Uri "$apiUrl/buildjobs/$jobId/artifacts" -Headers $headers
$artifactFileName = $artifacts[0].fileName
$localArtifactPath = "$downloadLocation\framerat-macos-rolling-$version_appveyor.zip"
Invoke-RestMethod -Method Get -Uri "$apiUrl/buildjobs/$jobId/artifacts/$artifactFileName" `
-OutFile $localArtifactPath -Headers @{ "Authorization" = "Bearer $token" }
