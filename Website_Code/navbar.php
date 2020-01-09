<?php

function renderNavbar($activeRoute){?>

        <nav id=navbar class="navbar sticky-top navbar-expand-lg navbar-dark bg-dark">
            <a class="navbar-brand" href="#"><i class="fas fa-dragon"></i> DB </a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarText" aria-controls="navbarText" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarText">
                <ul class="navbar-nav mr-auto">
                    <li class="nav-item <?php if($activeRoute == "DB_Accounts"){
                        echo "active";
                    }?>">
                        <a class="nav-link" href="DB_Accounts.php"></i> Accounts</a>
                    </li>
                    <li class="nav-item <?php if($activeRoute == "DB_Event"){
                        echo "active";
                    }?>">
                        <a class="nav-link" href="DB_Event.php"></i> Event</a>
                    </li>
                    <li class="nav-item <?php if($activeRoute == "DB_NummerPlaten"){
                        echo "active";
                    }?>">
                        <a class="nav-link" href="DB_NummerPlaten.php"></i> Nummerplaten</a>
                    </li>
                    <li class="nav-item <?php if($activeRoute == "DB_Foto"){
                        echo "active";
                    }?>">
                        <a class="nav-link" href="DB_Foto.php"></i> Foto's</a>
                    </li>
                </ul>
            </div>
        </nav>
<?php } ?>