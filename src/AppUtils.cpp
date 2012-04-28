// 
//  Copyright 2012 Andrew Okin
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#include "AppUtils.h"

void Utils::OpenFile(fs::path path)
{
	wxString cmd;
	wxOperatingSystemId osID = wxPlatformInfo::Get().GetOperatingSystemId();
	if ((osID & wxOS_WINDOWS) == wxOS_WINDOWS)
	{
		cmd = "explorer ";
	}
	else if ((osID & wxOS_MAC) == wxOS_MAC)
	{
		cmd = "open ";
	}
	else if ((osID & wxOS_UNIX_LINUX) == wxOS_UNIX_LINUX)
	{
		cmd = "xdg-open ";
	}
	else
	{
		wxMessageBox(_T("This feature is not supported by your OS."), _T("Error"));
		return;
	}
	cmd.append(settings.instanceDir.string());
	wxExecute(cmd);
}

int Utils::GetMaxAllowedMemAlloc()
{
	//wxMemorySize mem = wxGetFreeMemory();
	//if (mem < 0)
	//{
	//	// If we can't determine the amount of available memory, set the max to 65535
	//	return 65536;
	//}
	//else
	//{
	//	return mem
	//}
	return 65536;
}