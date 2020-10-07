import glob, os
from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive

from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
fid = '13ZaefmZjzaOuak7MLODByKAgYsXqbOIW'

gauth = GoogleAuth()
# Try to load saved client credentials
gauth.LoadCredentialsFile("mycreds.txt")
if gauth.credentials is None:
    # Authenticate if they're not there
    gauth.LocalWebserverAuth()
elif gauth.access_token_expired:
    # Refresh them if expired
    gauth.Refresh()
else:
    # Initialize the saved creds
    gauth.Authorize()
# Save the current credentials to a file
gauth.SaveCredentialsFile("mycreds.txt")
drive = GoogleDrive(gauth)

f = drive.CreateFile({"parents": [{"kind": "drive#fileLink", "id": fid}]})
#
#File path below shows the location of the exported file
#
f.SetContentFile(r'bme680/examples/roundTwo.txt')
f.Upload()
   
print ("File Uploaded")
