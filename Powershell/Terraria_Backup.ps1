$ErrorActionPreference = "Stop"
$world_folder_location = "C:\Users\Jeremy\Documents\My Games\Terraria\Worlds"
$staging_location = "C:\Users\Jeremy\Documents\My Games\Terraria\Staging"
$world_backup_location = "C:\Users\Jeremy\Documents\My Games\Terraria\Backup_Worlds"

# Backup for Terraria Worlds
Remove-Item $world_backup_location\* -Recurse -Force
md 'C:\Users\Jeremy\Documents\My Games\Terraria\Staging'
Copy-Item -Path $world_folder_location\* -Destination $staging_location -Recurse -Force
Copy-Item -Path $staging_location\* -Destination $world_backup_location -Recurse -Force
Remove-Item $staging_location -Recurse -Force